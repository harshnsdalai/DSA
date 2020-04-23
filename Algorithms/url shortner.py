map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
index = {}
for i in range(len(map)):
	index[map[i]] = i

def idToShortURL(id): 
	
	shortURL = "" 

	while(id > 0): 
		shortURL += map[id % 62] 
		id //= 62
 
	return shortURL[len(shortURL): : -1] 

def shortURLToId(shortURL):
	id = 0
	power=0
	for i in range(len(shortURL)-1,-1,-1):
		print(index[shortURL[i]],power)
		id+= (62**power) * index[shortURL[i]]
		power+=1
	return id


if (__name__ == "__main__"): 
	id = 123456789123456789
	shortURL = idToShortURL(id) 
	print("Short URL from 12345 is : ", shortURL) 
	print("ID from", shortURL, "is : ", shortURLToId(shortURL)) 
