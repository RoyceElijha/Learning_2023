#include <stdio.h>
#include <stdint.h>

void printExponent(double num) {
	    uint64_t* ptr = (uint64_t*)&num;  
	        
	        
	        uint64_t exponent = (*ptr >> 52) & 0x7FF;
		    
		    printf("Exponent (Hexadecimal): 0x%lX\n", exponent);
		        
		        
		        printf("Exponent (Binary): ");
			    for (int i = 10; i >= 0; i--) {
				            uint64_t bit = (exponent >> i) & 1;
					            printf("%ld", bit);
						        }
			        printf("\n");
}

int main() {
	    double x = 0.7;
	        
	        printf("Value: %lf\n", x);
		    printExponent(x);
		        
		        return 0;
}
