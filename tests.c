#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "lab2.h"

#define TEST_INT(task, expr, expected)                                                      \
    do                                                                                      \
    {                                                                                       \
        int actual = (expr);                                                                \
        if (actual != (expected))                                                           \
        {                                                                                   \
            printf("[ERROR] %s: %s == %d, expected %d\n", task, #expr, actual, (expected)); \
            assert(actual == (expected));                                                   \
        }                                                                                   \
    } while (0)

#define TEST_DOUBLE(task, expr, expected)                                                         \
    do                                                                                            \
    {                                                                                             \
        double actual = (expr);                                                                   \
        if (fabs(actual - (expected)) > 1e-9)                                                     \
        {                                                                                         \
            printf("[ERROR] %s: %s == %.10f, expected %.10f\n", task, #expr, actual, (expected)); \
            assert(fabs(actual - (expected)) <= 1e-9);                                            \
        }                                                                                         \
    } while (0)

#define TEST_STR(task, expr, expected)                                                      \
    do                                                                                      \
    {                                                                                       \
        const char *actual = (expr);                                                        \
        if (strcmp(actual, (expected)) != 0)                                                \
        {                                                                                   \
            printf("[ERROR] %s: %s == %s, expected %s\n", task, #expr, actual, (expected)); \
            assert(strcmp(actual, (expected)) == 0);                                        \
        }                                                                                   \
    } while (0)

void log_result(const char *task, const char *message)
{
    printf("[%s] %s\n", task, message);
}

int main(void)
{
    // ====== Task 1: Even or odd ======
    log_result("Task 1", "Starting tests");
    TEST_INT("Task 1", is_even(0), 1);
    TEST_INT("Task 1", is_even(1), 0);
    TEST_INT("Task 1", is_even(-2), 1);
    TEST_INT("Task 1", is_even(7), 0);
    log_result("Task 1", "All tests passed");

    // ====== Task 2: Maximum of three numbers ======
    log_result("Task 2", "Starting tests");
    TEST_INT("Task 2", max_of_three(1, 2, 3), 3);
    TEST_INT("Task 2", max_of_three(5, 5, 5), 5);
    TEST_INT("Task 2", max_of_three(-9, -3, -7), -3);
    TEST_INT("Task 2", max_of_three(-5, 0, -1), 0);
    log_result("Task 2", "All tests passed");

    // ====== Task 3: Sign of a number ======
    log_result("Task 3", "Starting tests");
    TEST_INT("Task 3", sign_of_number(12), 1);
    TEST_INT("Task 3", sign_of_number(0), 0);
    TEST_INT("Task 3", sign_of_number(-8), -1);
    log_result("Task 3", "All tests passed");

    // ====== Task 4: Absolute value ======
    log_result("Task 4", "Starting tests");
    TEST_INT("Task 4", absolute_value(0), 0);
    TEST_INT("Task 4", absolute_value(9), 9);
    TEST_INT("Task 4", absolute_value(-12), 12);
    TEST_INT("Task 4", absolute_value(-1), 1);
    log_result("Task 4", "All tests passed");

    // ====== Task 5: Triangle exists ======
    log_result("Task 5", "Starting tests");
    TEST_INT("Task 5", triangle_exists(3, 4, 5), 1);
    TEST_INT("Task 5", triangle_exists(1, 1, 3), 0);
    TEST_INT("Task 5", triangle_exists(2, 2, 3), 1);
    TEST_INT("Task 5", triangle_exists(10, 1, 1), 0);
    log_result("Task 5", "All tests passed");

    // ====== Task 6: Grade classification ======
    log_result("Task 6", "Starting tests");
    TEST_STR("Task 6", get_grade(0), "unsatisfactory");
    TEST_STR("Task 6", get_grade(59), "unsatisfactory");
    TEST_STR("Task 6", get_grade(60), "satisfactory");
    TEST_STR("Task 6", get_grade(75), "good");
    TEST_STR("Task 6", get_grade(90), "excellent");
    TEST_STR("Task 6", get_grade(101), "invalid");
    TEST_STR("Task 6", get_grade(-1), "invalid");
    log_result("Task 6", "All tests passed");

    // ====== Task 7: Euclidean distance ======
    log_result("Task 7", "Starting tests");
    TEST_DOUBLE("Task 7", euclidean_distance(0, 0, 3, 4), 5.0);
    TEST_DOUBLE("Task 7", euclidean_distance(1, 1, 1, 1), 0.0);
    TEST_DOUBLE("Task 7", euclidean_distance(-2, -3, 1, 1), 5.0);
    log_result("Task 7", "All tests passed");

    // ====== Task 8: Manhattan distance ======
    log_result("Task 8", "Starting tests");
    TEST_INT("Task 8", manhattan_distance(0, 0, 3, 4), 7);
    TEST_INT("Task 8", manhattan_distance(1, 1, 1, 1), 0);
    TEST_INT("Task 8", manhattan_distance(-2, -3, 1, 1), 7);
    log_result("Task 8", "All tests passed");

    // ====== Task 9: Average of prime numbers ======
    log_result("Task 9", "Starting tests");
    TEST_DOUBLE("Task 9", average_primes_in_interval(1, 10), 4.25);
    TEST_DOUBLE("Task 9", average_primes_in_interval(10, 1), 4.25);
    TEST_DOUBLE("Task 9", average_primes_in_interval(20, 25), 23.0);
    TEST_DOUBLE("Task 9", average_primes_in_interval(0, 1), 0.0);
    log_result("Task 9", "All tests passed");

    // ====== Task 10: Multiples ======
    log_result("Task 10", "Starting tests");
    TEST_INT("Task 10", count_multiples(1, 10, 3), 3);
    TEST_INT("Task 10", count_multiples(10, 1, 2), 5);
    TEST_INT("Task 10", count_multiples(-5, 5, 2), 5);
    TEST_INT("Task 10", count_multiples(1, 10, 0), 0);
    log_result("Task 10", "All tests passed");

    // ====== Task 11: Leap year ======
    log_result("Task 11", "Starting tests");
    TEST_INT("Task 11", is_leap_year(2000), 1);
    TEST_INT("Task 11", is_leap_year(1900), 0);
    TEST_INT("Task 11", is_leap_year(2024), 1);
    TEST_INT("Task 11", is_leap_year(2023), 0);
    log_result("Task 11", "All tests passed");

    // ====== Task 12: Season by month ======
    log_result("Task 12", "Starting tests");
    TEST_STR("Task 12", season_by_month(1), "winter");
    TEST_STR("Task 12", season_by_month(3), "spring");
    TEST_STR("Task 12", season_by_month(6), "summer");
    TEST_STR("Task 12", season_by_month(9), "autumn");
    TEST_STR("Task 12", season_by_month(12), "winter");
    TEST_STR("Task 12", season_by_month(0), "invalid");
    TEST_STR("Task 12", season_by_month(13), "invalid");
    log_result("Task 12", "All tests passed");

    // ====== Task 13: Day of week ======
    log_result("Task 13", "Starting tests");
    TEST_STR("Task 13", day_of_week(1), "monday");
    TEST_STR("Task 13", day_of_week(3), "wednesday");
    TEST_STR("Task 13", day_of_week(7), "sunday");
    TEST_STR("Task 13", day_of_week(0), "invalid");
    TEST_STR("Task 13", day_of_week(8), "invalid");
    log_result("Task 13", "All tests passed");

    // ====== Task 14: Count digits ======
    log_result("Task 14", "Starting tests");
    TEST_INT("Task 14", count_digits(0), 1);
    TEST_INT("Task 14", count_digits(7), 1);
    TEST_INT("Task 14", count_digits(12345), 5);
    TEST_INT("Task 14", count_digits(-1234), 4);
    log_result("Task 14", "All tests passed");

    // ====== Task 15: Reverse number ======
    log_result("Task 15", "Starting tests");
    TEST_INT("Task 15", reverse_number(0), 0);
    TEST_INT("Task 15", reverse_number(123), 321);
    TEST_INT("Task 15", reverse_number(-456), -654);
    TEST_INT("Task 15", reverse_number(1000), 1);
    log_result("Task 15", "All tests passed");

    printf("All tests passed successfully!\n");
    return 0;
}
