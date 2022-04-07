import requests
ploads = {'things':2,'total':25}

payload = str(input(""))#type the payload

p = requests.post('http://alanosys.online/toggle.php?state='+payload)
r = requests.get('http://alanosys.online/data.txt',params=ploads)

print(r.text)


