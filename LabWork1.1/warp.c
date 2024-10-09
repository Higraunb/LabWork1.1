#define _CRT_SECURE_NO_WARNINGS
#define CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#include "func.h"



int main()
{
    // ��������� ������ ��� ����������,�������, ����� � ������� 
    double random_number = 0, min_ch = 0, max_ch = 0, result = 0, number = 0;
    int count_of_numbers = 0, counter = 0, index_of_massive = 0, dec_remain, index, len_of_array = 1000000, * array_of_numbers = malloc(len_of_array * sizeof(int));
    double time_spent = 0.0;
    clock_t begin = 0, end = 0;
    FILE* file_of_numbers;
    for (counter = 0; counter < len_of_array; counter++)
    {
        array_of_numbers[counter] = 0;
    }
    // �������� ���������� �������������� 
    printf("Enter the minimum number to generate: ");
    scanf("%lf", &min_ch);
    printf("Enter the maximum number to generate: ");
    scanf("%lf", &max_ch);
    printf("Enter the count of generated numbers: ");
    scanf("%d", &count_of_numbers);
    // ������ ������ ������� 
    begin = clock();
    // �������� ����� ��� ���������
    file_of_numbers = fopen("stor.txt", "w");
    // �������� ��������� �����, ���������� �� �� ������� � ����� �����, ���������� ��� ����� � ���������� �������  
    for (counter = 0; counter < count_of_numbers; counter++)
    {
        // �������� ��������� �����
        random_number = make_random_number(min_ch, max_ch, counter);
        // ���������� �� ������� � ����� �����
        dec_remain = make_dec_remain(random_number);
        // ������� ��� ���������� �����, �.� � double ����� ��������� 7 ������ ����� �������, �� ��� �����, ����� ������� ������ 1000000, �� �� ���������� � ����
        if (counter < len_of_array)
        {
            // �������� �����, �� �������� �� ��� ���� 
            if (file_of_numbers != NULL)
                // ������ ����� � ����
                fprintf(file_of_numbers, "%lf\n", random_number);
            else
                printf("Eror ");
        }
        else
        {
            // ���� ������ ����� ������ 1000000 �� ��������� ��� 
            result += random_number;
        }
        // ���������� ������� �����
        if (dec_remain < len_of_array)
        {
            array_of_numbers[dec_remain] = 1;
        }
    }
    // �������� �����
    fclose(file_of_numbers);
    // �������� ����� ��� ������
    file_of_numbers = fopen("stor.txt", "r");
    if (count_of_numbers > 1000000)
        count_of_numbers = 1000000;
    // �������� ������� ����� � ���������� ����� �����
    for (counter = 0; counter < count_of_numbers; counter++)
    {
        fscanf(file_of_numbers, "%lf\n", &number);
        if (counter < len_of_array)
        {
            index = array_of_numbers[counter];
        }
        if (index == 1)
        {
            result -= number;
        }

        else
        {
            result += number;
        }
    }
    // �������� �����
    fclose(file_of_numbers);
    //��������� ������ �������
    end = clock();
    // ���������� ������� ������ ���������
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    // ������ ������� ������ ��������� � � ���������
    printf("Result: %lf.\nExcecution time: %lf seconds.", result, time_spent);
}