# import logging

# logging.basicConfig(filename='test.log',level=logging.INFO)

# def add(num1,num2):
#     return num1+num2
# def subtract(num1,num2):
#     return num1-num2
# def multiply(num1,num2):
#     return num1*num2
# def divide(num1,num2):
#     return num1/num2

# num1 = 20
# num2 = 10
# add_result = add(num1,num2)
# logging.debug(add_result)
# sub_result = subtract(num1,num2)
# logging.info(sub_result)
# mul_result = multiply(num1,num2)
# logging.warning(mul_result)
# div_result = divide(num1,num2)
# logging.critical(div_result)

import logging

logging.basicConfig(filename='demo_01.log',level=logging.DEBUG,format='%(asctime)s - %(levelname)s:%(name)s - %(message)s ')

def namecheck(name):
    if len(name) <2:
        logging.debug('checking for length')
        return 'Invalid name'
    elif name.isspace():
        logging.debug('checking for name has space')
        return 'Invalid name'
    elif name.isalpha():
        logging.debug('checking if name is alphabet')
        return 'valid name'
    elif name.replace(' ','').isalpha():
        logging.debug('checking for full name')
        return 'valid name'
    else:
        logging.debug('failed all checks')
        return 'Invalid name'

print(namecheck('imran'))