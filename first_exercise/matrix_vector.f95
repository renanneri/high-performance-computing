
program matrix_vector
  implicit none
  integer :: n
  double precision, allocatable :: A(:,:), b(:), x(:)
  real :: start_ij, finish_ij, start_ji, finish_ji
  integer :: i, j
  
  n = 1024
  do
    allocate(A(n,n),b(n),x(n))
    call random_number(A)
    call random_number(b)
    A = 4*A 
    b = 4*b
    A = nint(A)
    b = nint(b)
    x(:)=0.

    call cpu_time(start_ij)
    do i=1,n
    do j=1,n
        x(i)=x(i)+A(i,j)*b(j)
    enddo
    enddo
    call cpu_time(finish_ij)

    call cpu_time(start_ji)
    do j=1,n
    do i=1,n
        x(i)=x(i)+A(i,j)*b(j)
    enddo
    enddo
    call cpu_time(finish_ji)

    print*,n,",",finish_ij-start_ij,",",finish_ji-start_ji

    deallocate(A)
    deallocate(b)
    deallocate(x)
    n = n*2
  end do

end program matrix_vector