#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* ratings;      
    int totalScore;    
    float average;     
} Employee;
void inputEmployees(Employee* employees, int numEmployees, int numPeriods);
void displayPerformance(Employee* employees, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(Employee* employees, int numEmployees);
int findHighestRatedPeriod(Employee* employees, int numEmployees, int numPeriods);
int findWorstPerformingEmployee(Employee* employees, int numEmployees);
void freeMemory(Employee* employees, int numEmployees);

int main() {
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);
	if(numEmployees <= 0 || numPeriods <=0){
		printf("\nInvalid, input");
		return 1;
	}

    Employee* employees = (Employee*)malloc(numEmployees * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numEmployees; i++) {
        employees[i].ratings = (int*)malloc(numPeriods * sizeof(int));
        if (employees[i].ratings == NULL) {
            printf("Memory allocation failed for employee %d.\n", i + 1);
            freeMemory(employees, i);
            return 1;
        }
        employees[i].totalScore = 0;
        employees[i].average = 0.0;
    }

    inputEmployees(employees, numEmployees, numPeriods);
    displayPerformance(employees, numEmployees, numPeriods);
    int employeeOfTheYear = findEmployeeOfTheYear(employees, numEmployees);
    printf("Employee of the Year: Employee %d\n", employeeOfTheYear + 1);
    int highestRatedPeriod = findHighestRatedPeriod(employees, numEmployees, numPeriods);
    printf("Highest Rated Evaluation Period: Period %d\n", highestRatedPeriod + 1);
    int worstPerformingEmployee = findWorstPerformingEmployee(employees, numEmployees);
    printf("Worst Performing Employee: Employee %d\n", worstPerformingEmployee + 1);
    freeMemory(employees, numEmployees);
    return 0;
}

void inputEmployees(Employee* employees, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            int rating;
            do {
                printf("  Rating for Period %d (1-10): ", j + 1);
                scanf("%d", &rating);
                if (rating < 1 || rating > 10) {
                    printf("  Invalid rating. Please enter a rating between 1 and 10.\n");
                }
            } while (rating < 1 || rating > 10);
            employees[i].ratings[j] = rating;
            employees[i].totalScore += rating; 
        }
        employees[i].average = (float)employees[i].totalScore / numPeriods; 
    }
}
void displayPerformance(Employee* employees, int numEmployees, int numPeriods) {
    printf("\nEmployee Performance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", employees[i].ratings[j]);
        }
        printf("| Total Score: %d | Average Rating: %.2f\n", employees[i].totalScore, employees[i].average);
    }
}

int findEmployeeOfTheYear(Employee* employees, int numEmployees) {
    int bestEmployeeIndex = 0;
    float highestAverage = employees[0].average;

    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].average > highestAverage) {
            highestAverage = employees[i].average;
            bestEmployeeIndex = i;
        }
    }
    return bestEmployeeIndex;
}

int findHighestRatedPeriod(Employee* employees, int numEmployees, int numPeriods) {
    float highestAverage = 0.0;
    int bestPeriodIndex = 0;

    for (int j = 0; j < numPeriods; j++) {
        float periodTotal = 0.0;
        for (int i = 0; i < numEmployees; i++) {
            periodTotal += employees[i].ratings[j];
        }
        float periodAverage = periodTotal / numEmployees;
        if (periodAverage > highestAverage) {
            highestAverage = periodAverage;
            bestPeriodIndex = j;
        }
    }
    return bestPeriodIndex;
}

int findWorstPerformingEmployee(Employee* employees, int numEmployees) {
    int worstEmployeeIndex = 0;
    float lowestAverage = employees[0].average;

    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].average < lowestAverage) {
            lowestAverage = employees[i].average;
            worstEmployeeIndex = i;
        }
    }
    return worstEmployeeIndex;
}
void freeMemory(Employee* employees, int numEmployees) {
    for (int i = 0; i < numEmployees; i++) {
        free(employees[i].ratings);
    }
    free(employees);
}