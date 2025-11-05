/*
Name:Denis Macharia
Reg No:CT100/G/26250/25
The payroll
*/

#include <stdio.h>

int main() {
    float hours, wage, gross_pay, taxes, net_pay;
    float regular_hours = 40.0;
    float overtime_hours = 0.0;

    // Get user input
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);

    printf("Enter hourly wage: ");
    scanf("%f", &wage);

    // Calculate overtime if any
    if (hours > 40) {
        overtime_hours = hours - 40;
    }

    // Calculate gross pay
    gross_pay = (regular_hours * wage) + (overtime_hours * wage * 1.5);

    // Calculate taxes
    if (gross_pay <= 600) {
        taxes = 0.15 * gross_pay;
    } else {
        taxes = (0.15 * 600) + (0.20 * (gross_pay - 600));
    }

    // Calculate net pay
    net_pay = gross_pay - taxes;

    // Display results
    printf("\n--- PAYSLIP ---\n");
    printf("Gross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", net_pay);

return 0;
}