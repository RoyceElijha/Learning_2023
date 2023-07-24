#include <stdio.h>

int bit_operations(int num, int oper_type) {
	    switch (oper_type) {
		            case 1:
				                num |= (1 << 0);  
						            break;
							            case 2:
							                num &= ~(1 << 31);  
									            break;
										            case 3:
										                num ^= (1 << 15);  
												            break;
													            default:
													                printf("Invalid operation type.\n");
															            return num;
																        }
	        
	        return num;
}

int main() {
	    int number, operationType;
	        
	        printf("Enter an integer: ");
		    scanf("%d", &number);
		        
		        printf("Enter operation type (1 for set 1st bit, 2 for clear 31st bit, 3 for toggle 16th bit): ");
			    scanf("%d", &operationType);
			        
			        int result = bit_operations(number, operationType);
				    
				    printf("Result: %d\n", result);
				        
				        return 0;
}

