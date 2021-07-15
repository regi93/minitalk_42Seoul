모든 할당된 힙 영역은 반드시 적당하게 free되어야한다. 메모리 누수는 안된다.



◦ write 

◦ signal 

◦ sigemptyset 

◦ sigaddset 

◦ sigaction 

◦ kill 

◦ getpid 

◦ malloc 

◦ free 

◦ pause 

◦ sleep 

◦ usleep

◦ exit



## Mandatory Part

* 클라이언트와 서버의 폼 안에서 커뮤니케이션하는 프로그램을 만들어라
* 서버는 반드시 먼저 launch 되어야하고, 그리고 PID를 디스플레이해야한다.
* 클라이언트는 다음 파라미터를 취한다.
  * server PID
  * 송신된 문자열
* 클라이언트는 반드시 