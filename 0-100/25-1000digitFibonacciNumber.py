class low_precision_number:
    def __init__(self, first_4_digits, digits):
        self.front = first_4_digits
        self.digits = digits
        
    def __add__(self, num2):
        if self.digits > num2.digits + 3:
            return self
        elif self.digits + 3 < num2.digits:
            return num2
        else:
            difference = self.digits - num2.digits
            if difference>0:
                total = round(self.front + num2.front/10**(difference))
            elif difference<0:
                total = round(num2.front + self.front/10**(difference))
            else:
                total = round(num2.front + self.front)
            
            if total>=10000:
                return low_precision_number(round(total/10), max(self.digits, num2.digits) + 1)
            else:
                return low_precision_number(total, max(self.digits, num2.digits))
    
    def __str__(self):
        return str(self.front) + "0"*self.digits

prev2 = low_precision_number(1,0)
prev1 = low_precision_number(1,0)
for i in range(0,4800):
    new = prev1 + prev2
    prev2 = prev1
    prev1 = new
    if(new.digits + 4 == 1000):
        print(i+3)
        break

#output 4782
