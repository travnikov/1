/*
 прога для расчёта
 волнового диполя
 */
#include <stdio.h>
const float hu=0.3048;
const float zu=1.0333;

int main()
{
    float L,A,B,F,L1,A1,B1,Lv,H,Lx,Cx;
    float lz[10]={0.25,0.24,0.23,0.23,0.23,0.22,0.22,0.21,0.21,0.21};
    float lc[10]={62.0,61,58.7,57.6,56.6,55.5,54.5,53.6,52.7,51.8};
    float min=24.50,max=30.00;

    printf("       РАСЧЁТ ВОЛНОВОГО ДИПОЛЯ\n");
    printf("|<------------------L(L1)--------------->|\n");
    printf("|<-----A(A1)-->|<------------B(B1)------>|\n");
    printf("|                                        |\n");
    printf("*=============*==========================*\n");
    printf("                                          \n");
    printf("Верен от 24.5 do 30 MHz,D=1.5--2.0mm \n");
    printf("Оптимальная высота подвеса=Hопт, Длинна волны=Lv\n");
    printf("R (при оптимальной высоты подвеса)=80.Omh\n");
    printf("-------------------------------------------\n");
    while(F<50)
    {
    printf("введите частоту(24.5-30.0) MHz: ");
    scanf("%f",& F);
    if(F<min||F>max)
        {
        printf("%2.2f-недопустимо\n",F);
        continue;
        }

         Lv=299.781/F;
         H=Lv*0.65;
         L=((936/F)* hu)*zu;
         A=((234/F)* hu)*zu;
         B=((702/F)* hu)*zu;

         L1=L-((936/F)* hu)*0.03;
         A1=A-((234/F)* hu)*0.03;
         B1=B-((702/F)* hu)*0.03;

         if(F<=25){
         Lx=lz[0];
         Cx=lc[0];
         }
         else if (F<=26){
         Lx=lz[1];
         Cx=lc[1];
         }
          else if(F<=26.5){
         Lx=lz[2];
         Cx=lc[2];
         }
         else if(F<=27.0){
        Lx=lz[3];
        Cx=lc[3];
         }
        else if(F<=27.5){
        Lx=lz[4];
        Cx=lc[4];
         }
         else if(F<=28.0){
        Lx=lz[5];
        Cx=lc[5];
         }
         else if(F<=28.5){
        Lx=lz[6];
        Cx=lc[6];
         }
         else if(F<=29.0){
        Lx=lz[7];
        Cx=lc[7];
         }
         else if(F<=29.5){
        Lx=lz[8];
        Cx=lc[8];
         }
         else if(F<=30.0){
        Lx=lz[9];
        Cx=lc[9];
         }

    printf("Lv= %2.3f m\n",Lv);
    printf("Hопт.=%1.1f m\n",H);
    printf("              \n");
    printf("голый провод\n");
    printf("L= %2.4f m\n",L);
    printf("A= %2.4f m\n",A);
    printf("B= %2.4f m\n",B);
    printf("              \n");
    printf("изолированный провод\n");
    printf("L1= %2.4f m\n",L1);
    printf("A1= %2.4f m\n",A1);
    printf("B1= %2.4f m\n",B1);
    printf("                \n");
    printf("Г-соглосованние при Нопт:\n");
    printf("               Lx              \n");
    printf("  50 Omh <---========----*---> ANT\n");
    printf("                        |      \n");
    printf("                     Cx =      \n");
    printf("                        |      \n");
    printf("                        -      \n");
    printf("Lx= %2.2f uH\n",Lx);
    printf("Cx= %2.1f pF\n",Cx);
    printf("-------------------------------------------\n");
    }
    return 0;
}
