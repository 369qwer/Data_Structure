#pragma once

//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//status �Ǻ������ͣ�ֵΪ�������״̬����
typedef int Status;

typedef int ElemType;//int �ɸ���Ϊ��Ҫ����������

typedef Status(*Compare)(ElemType, ElemType); // ������һ����ΪCompare��ָ������ָ������