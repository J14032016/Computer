list = [1,1,2,2,3,3,4]
list_new = []
for var in list:
    if var not in list_new:
        list_new.append(var)
    
print list_new    
