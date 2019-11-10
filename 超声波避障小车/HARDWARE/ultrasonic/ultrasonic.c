#include "ultrasonic.h"
#include "delay.h"
#include "timer.h"

extern u8  TIM2CH1_CAPTURE_STA;
extern u16 TIM2CH1_CAPTURE_VAL;
int  distance = 0;
u16 Ultra_Distance(void)
{

    u16 time;

    GPIO_SetBits(GPIOC,GPIO_Pin_3);
    delay_us(10);//20us
    GPIO_ResetBits(GPIOC,GPIO_Pin_3);
//ģ���Զ�����8��40khz�ķ������Զ�����Ƿ����źŷ���
    if(TIM2CH1_CAPTURE_STA&0x80)
    {
        time = TIM2CH1_CAPTURE_STA&0x3f;//�������
        time *=65536;
        time+=TIM2CH1_CAPTURE_VAL;
        distance=time *170;
        distance /= 10000;
        if((distance>0)&&(distance<1000))
        {
			 if ((distance<1000)&&(distance>21))

            {

                dianji1IN1=1;
                dianji1IN2=0;
                TIM_SetCompare2(TIM3,1500);//����
                dianji2IN1=1;
                dianji2IN2=0;
                TIM_SetCompare3(TIM3,1800); //����
            }
            if ((distance<=17)&&(distance>13))

            {

                dianji1IN1=1;
                dianji1IN2=0;
                TIM_SetCompare2(TIM3,1700);//����
                dianji2IN1=1;
                dianji2IN2=0;
                TIM_SetCompare3(TIM3,1700); //����
            }
			if((distance>17)&&(distance<=21))
			{
                dianji1IN1=1;
                dianji1IN2=0;
                TIM_SetCompare2(TIM3,1700);//����
                dianji2IN1=1;
                dianji2IN2=0;
                TIM_SetCompare3(TIM3,1700); //����			
			}


            if ((distance<=13)&&(distance>9))//���Ҳ�ƫ

            {

                dianji1IN1=1;
                dianji1IN2=0;
                TIM_SetCompare2(TIM3,1350);//����
                dianji2IN1=1;
                dianji2IN2=0;
                TIM_SetCompare3(TIM3,1900); //����
            }
//            if((distance>21)&&(distance<=25))
//            {
//                dianji1IN1=1;
//                dianji1IN2=0;
//                TIM_SetCompare2(TIM3,1000);//����
//                dianji2IN1=1;
//                dianji2IN2=0;
//                TIM_SetCompare3(TIM3,1300); //����
//            }

            if ((distance<=9)&&(distance>5))//���Ҳ�ƫ

            {

                dianji1IN1=1;
                dianji1IN2=0;
                TIM_SetCompare2(TIM3,1900);//����
                dianji2IN1=1;
                dianji2IN2=0;
                TIM_SetCompare3(TIM3,1300); //����
            }
//            if((distance>25)&&(distance<=29))
//            {
//                dianji1IN1=1;
//                dianji1IN2=0;
//                TIM_SetCompare2(TIM3,1000);//����
//                dianji2IN1=1;
//                dianji2IN2=0;
//                TIM_SetCompare3(TIM3,1400); //����
//            }

            if ((distance<=5)&&(distance>2))//���Ҳ�ƫ

            {

                dianji1IN1=1;
                dianji1IN2=0;
                TIM_SetCompare2(TIM3,1900);//����
                dianji2IN1=1;
                dianji2IN2=0;
                TIM_SetCompare3(TIM3,1250); //����
            }
//            if((distance>29)&&(distance<=33))
//            {
//                dianji1IN1=1;
//                dianji1IN2=0;
//                TIM_SetCompare2(TIM3,1000);//����
//                dianji2IN1=1;
//                dianji2IN2=0;
//                TIM_SetCompare3(TIM3,1500); //����
//            }


        }
//        if(distance>34)//�������34ʱ��ֹͣת��
//        {
//            TIM_SetCompare2(TIM3,1999);
//            TIM_SetCompare3(TIM3,1999);
//        }

        TIM2CH1_CAPTURE_STA=0;//������һ�β���
    }

    return distance;
}

