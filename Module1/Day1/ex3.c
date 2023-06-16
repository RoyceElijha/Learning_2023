#include <stdio.h>

struct Student {
	    int rollNo;
	        char name[50];
		    float physicsMarks;
		        float mathMarks;
			    float chemistryMarks;
};

void printSummary(struct Student student) {
	    float totalMarks = student.physicsMarks + student.mathMarks + student.chemistryMarks;
	        float percentage = (totalMarks / 300) * 100;

		    printf("Roll No: %d\n", student.rollNo);
		        printf("Name: %s\n", student.name);
			    printf("Physics Marks: %.2f\n", student.physicsMarks);
			        printf("Math Marks: %.2f\n", student.mathMarks);
				    printf("Chemistry Marks: %.2f\n", student.chemistryMarks);
				        printf("Total Marks: %.2f\n", totalMarks);
					    printf("Percentage: %.2f%%\n", percentage);
}

int main() {
	    struct Student student;
	        
	        printf("Enter Roll No: ");
		    scanf("%d", &student.rollNo);
		        
		        printf("Enter Name: ");
			    scanf(" %[^\n]s", student.name);
			        
			        printf("Enter Marks of Physics: ");
				    scanf("%f", &student.physicsMarks);
				        
				        printf("Enter Marks of Math: ");
					    scanf("%f", &student.mathMarks);
					        
					        printf("Enter Marks of Chemistry: ");
						    scanf("%f", &student.chemistryMarks);
						        
						        printf("\n--- Summary ---\n");
							    printSummary(student);
							        
							        return 0;
}

