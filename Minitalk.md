# Minitalk



### #1 Signal



### Signal() - 인터럽트 신호처리



### prototype

```c
#include <signal.h>
void ( *signal(int sig, void(*func)(int)) )(int);
```

`signal()`함수를 사용하여 프로그램이 운영체제나 raise()함수에서 인터럽트 신호를 처리할 수 있는 여러 방법 중 하나를 선택할 수 있다.



### signal()

```
handler_t *signal(int signum, handler_t *handler);
```

- ```text
  signum
  ```

  - 시그널의 번호

- ```text
  handler
  ```

  - 시그널이 발생하면 핸들링할 함수 (javascript의 이벤트 리스너 같은 느낌?)













### Pid 식별번호

pid의 최대값 확인

```shell
$ cat /proc/sys/kernel/pid_max 
>>> 최대값 : 32768
```



* Processs Identifier (프로세스 식별자)
* `getpid()`

### kill

https://www.lesstif.com/system-admin/unix-linux-kill-12943674.html



* 프로세스에서 시그널 전송하는 함수.
* header : signal.h
* prototype : `int kill(pid_t pid, int sig)`
* int sig 는 시그널 번호
* 성공시 0,  실패시 -1리턴
* 특정 프로세스 뿐 아니라, 같은 PID의 모든 프로세스에서 동시에 시그널을 전송할 수 있다.
* 시그널의 종류는 터미널에서 `kill -l`
![image](https://user-images.githubusercontent.com/46234386/133193823-2e275e40-c1f3-43e3-8a0e-569f1615d94f.png)


* usleep 왜 필요한거지 .. ?
* signal 함수를 한번 실행시켜놓으면 계속  유지되는건가 .. .?
* signal의 첫번째 인자 SIGUSR1 , SIGUSR2

* pid_max 최대값
* 





### raise

```c
#include <signal.h>
int raise(int sig);
```

프로세스 자신에게 시그널을 보낼 때 사용된다. 보통 실행중인 프로그램에 시그널을 보낼때 사용된다.

`kill(getpid(), sig)` 와 같은코드이다.



### getpid, get-pic

```c
#inlcude <sys.types.h>
#include <unistd.h>
pid_t getpid(void); // 현재 프로세스의 pid 리턴
pid_t getppid(void); // 부모 프로세스의 pid 리턴
```





### interrupt

단어 그대로는 중단 및 새치기를 의미한다. 프로그램 실행중에 입출력 하드웨어등에서 예외상황이 발생하여 처리가 필요한 경우에 이를 먼저 처리하도록 하는것을 말한다.





### Usleep

기본적으로 프로젝트 프로세싱이 비동기 인터럽트이다. sleep없이 client단에서 signal을 보내게 되면 순서가 꼬이거나, 서버가 시그널을 받고있는 도중 시그널을 보내면 손실위험이 있다.





### 인터럽트 핸들러

마이크로프로세서에서 인터럽트가 접수되면, 해당 인터럽트 핸들러의 코드를 찾아 실행한다. 핸들링이 완료되면, 이전의 상태로 다시 복귀한다.



### 유니코드

유니코드는 글자와 코드가 1:1 mapping 되어있는 코드표이다.



### UTF-8

인코딩 : 컴퓨터가 이해할 수 있는 형태로 바꿔주는것을 말한다.

UFF-8은 유니코드를 인코딩하는 방식을 국제 표준으로 약속한것이다. 가변 인코딩 방식이며, 이것은 글자마다 byte길이가 다르다는것을 의미한다. 예를들어 'a'는 1byte이고 '가'는 3byte이다. 

* U+0000~U+007F : UTF-8 Encoding 0xxx xxxx 8bit (총 1byte)

* U+0080~U+07FF : UTF-8 Encoding 110x xxxx 10xx xxxx 16bit (총 2byte)

* U+0800~U+7FFF : UTF-8 Encoding 1110 xxxx 110x xxxx 10xx xxxx 24bit (총 3byte)

* U+10000~U+10FFFF : UTF-8 Encoding 1111 0xxx 10xx xxxx 10xx xxxx 10xx xxxx 32bit (총 4byte)

UTF-8 변환 사이트

https://www.branah.com/unicode-converter

```c
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *arr;

	arr = (char *)malloc(sizeof(char) * 4);
	arr[0] = 0b11110000;
	arr[1] = 0b10011111;
	arr[2] = 0b10010011;
	arr[3] = 0b10100011;

	write(1, &arr[0], 1);
	write(1, &arr[1], 1);
	write(1, &arr[2], 1);
	write(1, &arr[3], 1);

	char *ko;
	ko = (char *)malloc(sizeof(char) * 4);
	// 휅 UTF-8 16진수 : \xed\x9c\x85
	ko[0] = 0xed;
	ko[1] = 0x9c;
	ko[2] = 0x85;
	write(1, &ko[0], 1);
	write(1, &ko[1], 1);
	write(1, &ko[2], 1);
}
```



https://jeongdowon.medium.com/unicode%EC%99%80-utf-8-%EA%B0%84%EB%8B%A8%ED%9E%88-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-b6aa3f7edf96



### UNIX signal을 이용한 문자열 전송





* a

  0110 0001 **0111 1111**

  0:1
  64:1
  96:1

  0:1
  64:1
  96:1
  112:1
  120:1
  124:1
  126:1

* 가

  1110 1010 1011 0000 1000 0000 **0111 1111**





![image](https://user-images.githubusercontent.com/46234386/133193862-926da224-131b-4049-b3a9-147288539325.png)






### PID에 잘못된 input값이 들어오면?

잘못된 Identifier를 입력한것까지 예외처리하는것은 투머치, 식별자에대한 의미가 없어진다.











https://bingu.tistory.com/m/5 


https://www.notion.so/minitalk-Inter-Process-Communication-0b8ee4bb511c465e9a09fe70e00c9f96








