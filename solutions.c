#include "lab2.h" // обращаем внимание, файл изменился!!!
#include <math.h> // а вы как думали, подлянки везде
#include <stdio.h>

// Вставьте свою реализацию вместо этого файла!

#include <stdlib.h>

// Task 1 - Even or odd
int is_even(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Task 2 - Maximum of three numbers
int max_of_three(int a, int b, int c)
{
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

// Task 3 - Sign of a number
int sign_of_number(int n)
{
    if (n > 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// Task 4 - Absolute value
int absolute_value(int n)
{
    if (n < 0)
    {
        return -n;
    }
    else
    {
        return n;
    }
}

// Task 5 - Triangle existence
int triangle_exists(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Task 6 - Grade classification
const char *get_grade(int score)
{
    if (score >= 90 && score <= 100)
    {
        return "excellent";
    }
    else if (score >= 75 && score < 90)
    {
        return "good";
    }
    else if (score >= 60 && score < 75)
    {
        return "satisfactory";
    }
    else if (score >= 0 && score < 60)
    {
        return "unsatisfactory";
    }
    else
    {
        return "invalid";
    }
}

// Task 7 - Euclidean distance
double euclidean_distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

// Task 8 - Manhattan distance
int manhattan_distance(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

// Helper function to check whether a number is prime.
int is_prime(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Task 9 - Average of prime numbers in an interval
double average_primes_in_interval(int a, int b)
{
    int start = a;
    int end = b;
    if (start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }

    int sum = 0;
    int count = 0;

    for (int i = start; i <= end; i++)
    {
        if (is_prime(i))
        {
            sum += i;
            count++;
        }
    }

    if (count == 0)
    {
        return 0.0;
    }

    return (double)sum / count;
}

// Task 10 - Count multiples in an interval
int count_multiples(int start, int end, int k)
{
    if (k == 0)
    {
        return 0;
    }

    if (start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }

    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (i % k == 0)
        {
            count++;
        }
    }

    return count;
}

// Task 11 - Leap year
int is_leap_year(int year)
{
    if (year % 400 == 0)
    {
        return 1;
    }
    if (year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    return 0;
}

// Task 12 - Season by month number
const char *season_by_month(int month)
{
    if (month == 12 || month == 1 || month == 2)
    {
        return "winter";
    }
    if (month >= 3 && month <= 5)
    {
        return "spring";
    }
    if (month >= 6 && month <= 8)
    {
        return "summer";
    }
    if (month >= 9 && month <= 11)
    {
        return "autumn";
    }
    return "invalid";
}

// Task 13 - Day of the week
const char *day_of_week(int day_num)
{
    switch (day_num)
    {
    case 1:
        return "monday";
    case 2:
        return "tuesday";
    case 3:
        return "wednesday";
    case 4:
        return "thursday";
    case 5:
        return "friday";
    case 6:
        return "saturday";
    case 7:
        return "sunday";
    default:
        return "invalid";
    }
}

// Task 14 - Count digits in a number
int count_digits(int n)
{
    int count = 0;
    int value = n;

    if (value == 0)
    {
        return 1;
    }

    if (value < 0)
    {
        value = -value;
    }

    do
    {
        value /= 10;
        count++;
    } while (value > 0);
    return count;
}

// Task 15 - Reverse a number
int reverse_number(int n)
{
    int result = 0;
    int value = n;

    if (value == 0)
    {
        return 0;
    }

    if (value < 0)
    {
        value = -value;
    }

    do
    {
        result = result * 10 + (value % 10);
        value /= 10;
    } while (value > 0);

    if (n < 0)
    {
        result = -result;
    }

    return result;
}
