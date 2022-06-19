#include<stdio.h>
#include<math.h>

//@�������������㣻

typedef struct 
{
    float realpart;//ʵ����
    float imaqpart;//�鲿��
}Complex;          //���帴���������ͣ�

void assign(Complex *A,float real,float imag);    //��ֵ��
void add(Complex *C,Complex A,Complex B);         //A+B��
void minus(Complex *C,Complex A,Complex B);       //A-B��
void multiply(Complex *C,Complex A,Complex B); //A*B��
void divide(Complex *C,Complex A,Complex B);   //A/B��

void assign(Complex *A,float real,float imag)     //��ֵ��
{
    A->realpart=real;
    A->imaqpart=imag;
}

void add(Complex *C,Complex A,Complex B)          //A+B��
{
    C->realpart=(A.realpart)+(B.realpart);
    C->imaqpart=(A.imaqpart)+(B.imaqpart);
}

void minus(Complex *C,Complex A,Complex B)       //A-B��
{
    C->realpart=(A.realpart)-(B.realpart);
    C->imaqpart=(A.imaqpart)-(B.imaqpart);
}

void divide(Complex *C,Complex A,Complex B)     //A*B��
{
    C->realpart=((A.realpart)*(B.realpart))-((A.imaqpart)*(B.imaqpart));
    C->imaqpart=((A.realpart)*(B.imaqpart))+((A.imaqpart)*(B.realpart));
}

void multiply(Complex *C,Complex A,Complex B)     //A/B��
{
    C->realpart=(((A.realpart)*(B.realpart))+((A.imaqpart)*(B.imaqpart)))/((B.imaqpart)*(B.imaqpart)+(B.realpart)*(B.realpart));
    C->imaqpart=((A.imaqpart)*(B.realpart)-(A.realpart)*(B.imaqpart))/((B.imaqpart)*(B.imaqpart)+(B.realpart)*(B.realpart));
}

int main()
{
    int*a;
    Complex z1,z2,z3,z4,z5,z6;
    float RealPart,ImagPart;
    assign(&z1,8.0,6.0);
    assign(&z2,4.0,3.0);
    add(&z3,z1,z2);//z1+z2;
    minus(&z4,z1,z2);//z1-z2;
    divide(&z5,z1,z2);//z1*z2;
    multiply(&z6,z1,z2);//z1/z2;
    printf("�ӷ�:\nʵ����%f\n�鲿��%f\n\n",z3.realpart,z3.imaqpart);
    printf("����:\nʵ����%f\n�鲿��%f\n\n",z4.realpart,z4.imaqpart);
    printf("�˷�:\nʵ����%f\n�鲿��%f\n\n",z5.realpart,z4.imaqpart);
    printf("����:\nʵ����%f\n�鲿��%f\n\n",z6.realpart,z4.imaqpart);
    return 0;
}