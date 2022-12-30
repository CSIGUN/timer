#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(){

	int count = 0;
	time_t timer;
	struct tm* t;
	//int setHour = 20;	//24Hour
	//int setMin = 56;
	int setSec = 60;
	char check;

	int setHour=0,setMin=0;
	printf("24시간 time으로 입력하세요\n\n");
	printf("몇 시?: ");
	scanf("%d", &setHour);
	if(setHour < 13){
		printf("오전 %d시가 맞습니까?(맞으면 y, 아니면 n -> +12시간): ", setHour);
		scanf(" %c",&check);
		if(check=='n')
			setHour=setHour+12;
	}
	printf("\n");
	printf("몇 분?: ");
	scanf("%d", &setMin);

	int visibleHour=0, visibleMin=0, visibleSec=0;
	timer = time(NULL);
	t = localtime(&timer);

		
	visibleHour = setHour-(t->tm_hour);		//종료시간 - 현재시간
	//분 처리
	if(setMin < t->tm_min){
			visibleMin = (setMin-1)+60-(t->tm_min);
			visibleHour = visibleHour-1;
	}
	else{
		visibleMin = (setMin-1)-(t->tm_min);	//종료분 - 현재분
	}
	//초 처리
	visibleSec = setSec-(t->tm_sec)-1;		//60초 - 현재초

	while(1){
		
		//타이머 다되면 끝내기
		if(visibleHour==0 &&visibleMin==0 && visibleSec==0){
			break;
		}
		
		//초 계산
		if(visibleSec > 0){
			visibleSec = visibleSec - 1;
		}
		else{
			visibleSec = 59;
			if(visibleMin > 0){
				visibleMin = visibleMin-1;
			}
			else{
				visibleMin = 59;
				if(visibleHour > 0){
					visibleHour = visibleHour - 1;
				}
				else{
					visibleHour = 0;
				}
			}
		}


		printf("남은 시간 : %d시간 %d분 %d초",visibleHour, visibleMin, visibleSec);
		fflush(stdout);
		printf("\r");
		count++;
		sleep(1);
	}
	printf("FINISHED-!!\n");
	sleep(1);
	timer = time(NULL);
	t = localtime(&timer);
	printf("%d년 %d월 %d일 %d시 %d분\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);
}


