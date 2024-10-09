#define _CRT_SECURE_NO_WARNINGS
#define CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#include "func.h"



int main()
{
    // выделение пам€ти дл€ переменных,массива, файла и таймера 
    double random_number = 0, min_ch = 0, max_ch = 0, result = 0, number = 0;
    int count_of_numbers = 0, counter = 0, index_of_massive = 0, dec_remain, index, len_of_array = 1000000, * array_of_numbers = malloc(len_of_array * sizeof(int));
    double time_spent = 0.0;
    clock_t begin = 0, end = 0;
    FILE* file_of_numbers;
    for (counter = 0; counter < len_of_array; counter++)
    {
        array_of_numbers[counter] = 0;
    }
    // введение переменных пользовательем 
    printf("Enter the minimum number to generate: ");
    scanf("%lf", &min_ch);
    printf("Enter the maximum number to generate: ");
    scanf("%lf", &max_ch);
    printf("Enter the count of generated numbers: ");
    scanf("%d", &count_of_numbers);
    // начало работы таймера 
    begin = clock();
    // открытие файла дл€ заполнени
    file_of_numbers = fopen("stor.txt", "w");
    // создание рандомных чисел, разделение их на дробную и целую часть, заполнение ими файла и присвоение индекса  
    for (counter = 0; counter < count_of_numbers; counter++)
    {
        // создание рандомных чисел
        random_number = make_random_number(min_ch, max_ch, counter);
        // разделение на дробную и целую часть
        dec_remain = make_dec_remain(random_number);
        // условие дл€ заполнение файла, т.к в double может хранитьс€ 7 знаков после з€п€той, то все числа, номер которых больше 1000000, мы не записываем в файл
        if (counter < len_of_array)
        {
            // проверка числа, не €вл€етс€ ли оно нулЄм 
            if (file_of_numbers != NULL)
                // запись чисел в файл
                fprintf(file_of_numbers, "%lf\n", random_number);
            else
                printf("Eror ");
        }
        else
        {
            // если индекс числа больше 1000000 то суммируем его 
            result += random_number;
        }
        // присваение индекса числу
        if (dec_remain < len_of_array)
        {
            array_of_numbers[dec_remain] = 1;
        }
    }
    // закрытие файла
    fclose(file_of_numbers);
    // открытие файла дл€ чтени€
    file_of_numbers = fopen("stor.txt", "r");
    if (count_of_numbers > 1000000)
        count_of_numbers = 1000000;
    // проверка индекса числа и вычисление суммы чисел
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
    // закрытие файла
    fclose(file_of_numbers);
    //окончание работы таймера
    end = clock();
    // вычисление времени работы программы
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    // ввывод времени работы программы и еЄ результат
    printf("Result: %lf.\nExcecution time: %lf seconds.", result, time_spent);
}