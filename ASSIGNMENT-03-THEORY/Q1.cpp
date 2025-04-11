#include <stdio.h>
#include <string.h>


struct Employee {
	int employeeCode;
	char employeeName[20];
	char dateOfJoining[10];
};


struct Employee createEmployee() {
	struct Employee employee;


	printf("ENTER EMPLOYEE CODE: ");
	scanf("%d", &employee.employeeCode);
	fflush(stdin);

	printf("ENTER NAME OF EMPLOYEE: ");
	fgets(employee.employeeName, sizeof(employee.employeeName), stdin);
	if (strlen(employee.employeeName) > 0 && employee.employeeName[strlen(employee.employeeName)] == '\n') {
		employee.employeeName[strlen(employee.employeeName) - 1] = '\0';
	}
	printf("ENTER DATE OF JOINING (MM-DD-YY): ");
	scanf("%s", employee.dateOfJoining);
	return employee;
}
void checkEmployeeTenure(struct Employee employee,int * count) {
	int joiningYear, currentYear;
	char currentDate[20];
	sscanf(employee.dateOfJoining, "%*d-%*d-%d", &joiningYear);
	printf("ENTER THE CURRENT DATE (MM-DD-YY): ");
	scanf("%s", currentDate);
	sscanf(currentDate, "%*d-%*d-%d", &currentYear);
	if (currentYear - joiningYear > 3) {
		printf("\nEMPLOYEE CODE: %d", employee.employeeCode);
		printf("\nNAME: %s", employee.employeeName);
		printf("DATE OF JOINING: %s", employee.dateOfJoining);
		printf("\nSTATUS: TENURE EXCEEDS 3 YEARS\n");
		*count+=1;
	}
}

int main() {
	struct Employee employeeList[4];
	int count=0;
	for (int i = 0; i < 4; i++) {
		printf("\nENTER DETAILS FOR EMPLOYEE %d:\n", i + 1);
		employeeList[i] = createEmployee();
		checkEmployeeTenure(employeeList[i],&count);
	}
	printf("\n\nCOUNT OF EMPLOYEE WITH EXCEEDING 3 YEAR TENURE %d",count);

	return 0;
}
