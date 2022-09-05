//First Come First Serve FCFS Turkce Kod

#include <stdio.h>
#include <conio.h>
#define maks 30 //maksimum degeri 30 olarak atadik


void main()
{
	int i, j, sayi, burst_time[maks], waiting_time[maks], turnaround[maks];
	float awt = 0, atat = 0;// Ortalama bekleme suresi awt, ortalama turnaround time atat
	printf("Process sayisini giriniz : ");
	scanf("%d",&sayi);
	printf("Processlerin burst time degerlerini giriniz : ");
	
	for(i = 0; i< sayi; i++)//Burst timelari aldigimiz dongu
	{
		scanf("%d",&burst_time[i]);
	}
	
	printf("Process\tBurstTime\tWaitingTime\tTurnaroundTime\t");
	
	for(i = 0; i<sayi; i++)
	{
		waiting_time[i] = 0;
		turnaround[i] = 0;
		for(j = 0; j<sayi; j++)//Her bir process'in waiting time'ini bulmak icin dongu
		{
		  waiting_time[i] = waiting_time[i] + burst_time[j];			
		}
		turnaround[i] = waiting_time[i] + burst_time[i];//Matematiksel hesaplamalar
		awt = awt + waiting_time[i];
		atat = atat + turnaround[i];
		printf("\n%d\t%d\t\t%d\t\t%d",i+1,burst_time[i],waiting_time[i],turnaround[i]);
	}
	
	awt = awt/sayi;
	atat = atat/sayi;
	printf("\nOrtalama Waiting Time : %d\n",awt);
	printf("Ortalama Turnaround Time : %d",atat);
	getch();
}


