모든 할당된 힙 영역은 반드시 적당하게 free되어야한다. 메모리 누수는 안된다.



◦ write 

◦ signal 

◦ sigemptyset 

◦ sigaddset 

◦ sigaction 

◦ kill 

◦ getpid 



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



## KILL 

`kill()`함수는 쉘 명령어 `$kill`과는 다르게 프로세스에 시그널을 전송한다. 

프로서에 `Sigkill()`을 보내면 쉘 명령의 kill같은 역할을 하게 된다.



### kill()

* Header : `signal.h`
* Prototype : `int kill(pid_t pid, int sig)`
  * `pid_t pid` : pid 번호
  * `sig` : 시그널 번호
* Return : 성공시 0, 실패시 -1을 반환한다.



### pid (Process id)

* pid > 0 : 지정한 프로세스 ID에 시그널을 전송한다.
* pid == 0 : 함수 호출하는 프로세스와 같은 그룹의 모든 프로세스에 시그널을 전송한다.
* pid == -1 : 함수 호출하는 프로세스가 전송할 수 있는 권한을 가진 모든 프로세스에 시그널을 전송한다.
* pid < -1 : 첫 번째 인수 pid의 절대값 프로세스 그룹에 속하는 모든 프로세스에 시그널을 전송한다.
* 





## getpid

현재 프로세스의 PID를 얻는 함수이다. PID는 프로세스가 생성된 순서대로 번호를 순차 할당한다. 그리고 실행중인 프로세스가 종료되었다고 해서, 비어있는 PID를 사용하지 않는다. PID의 Maximum 번호에 다다르면, 다시 1번부터 시작하여 할당한다.







## 프로세스의 구성요소



### PID(Process IDentifier)

프로세스 식별자, 유닉스 커널과 같은 운영체제에서 프로세스나 서비스를 식별하기 위해 할당하는 고유 번호이다.



### PPID

현재 프로세스를 만든 부모 프로세스를 나타낸다.



### UID

프로그램을 실행한 사람의 정보를 나타낸다.



### $PS

쉘에서 ps명령어를 이용하여 실행중인 모든 프로세스의 pid, ppid, pgid.....를 검색할 수 있다.

`ps -A -o pid, ppid, uid, command`

### 





































