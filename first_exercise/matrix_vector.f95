
! This program will do Ab = x multiplication
! where A is an N by N matrix and b and x are
! N vectors.
! The program will perform this multiplication
! using row-major and column-major methods
! 10 times for each N value where N starts with
! 1000 and increase by 1000 every time till the
! program be killed by the system or the user.

program matrix_vector
  implicit none

  ! variable declaration
  integer :: n
  double precision, allocatable :: A(:,:), b(:), x(:)
  real :: start_ij, finish_ij, start_ji, finish_ji
  integer :: i, j, exec
  
  n = 1000

  ! infinite loop
  do
    allocate(A(n,n),b(n),x(n))
    call random_number(A)
    call random_number(b)
    
    ! do the multiplication 10 times
    ! for each N value
    do exec=1,10

      ! Assign 0s to the vector
      x(:)=0.

      ! Perform row-major multiplication
      call cpu_time(start_ij)
      do i=1,n
      do j=1,n
          x(i)=x(i)+A(i,j)*b(j)
      enddo
      enddo
      call cpu_time(finish_ij)
      
      ! Assign 0s to the vector again
      x(:)=0.
      
      ! Perform column-major multiplication
      call cpu_time(start_ji)
      do j=1,n
      do i=1,n
          x(i)=x(i)+A(i,j)*b(j)
      enddo
      enddo
      call cpu_time(finish_ji)

      ! Print the execution time in csv form
      print*,n,",",exec,",",finish_ij-start_ij,",",finish_ji-start_ji

    enddo

    ! deallocate variables
    deallocate(A)
    deallocate(b)
    deallocate(x)

    ! increase N
    n = n+1000
  end do

end program matrix_vector