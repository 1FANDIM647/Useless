import smtplib
from email.mime.text import MIMEText 
from email.mime.multipart import MIMEMultipart

def send_mail():
	login = "fandimfromitaly@yandex.ru"

	password = 'elkin4742'

	url = "smtp.yandex.ru"
	toaddr = "Sulejmanovainzi@gmail.com"

	msg = MIMEMultipart()
	msg['Subject'] = "Adding in Data Base"
	msg['From'] = "fandimfromitaly@yandex.ru"
	body = 'Hello , it is test'
	msg.attach(MIMEText(body, 'plain'))

	try:
		server = smtplib.SMTP_SSL(url , 465)
	except TimeoutError:
		print('no connect')
	server.login(login , password)
	server.sendmail(login , toaddr , msg.as_string())
	server.quit()	
def main():
	send_mail()
	




if __name__ == '__main__':
	main()



      
