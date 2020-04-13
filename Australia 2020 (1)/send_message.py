import smtplib as root
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

def send_email():
	login  = input ('Введите вашу почту:')
	password = input ('Введите пароль от почты:')
	url = input ('URL:')
	toaddr = input ('tema:')
	message = input ('Сообщение:')

	msg = MIMEMultipart()

	msg['Subject'] = topic
	msg['From'] = login
	body = massage
	msg.attach(MIMEText(body , 'palin'))

	server = root.SMTP_SSL (url , 465)
    server.login( login , password)
    server.sendmail(login , toaddr, msg.as_string())

def main():
	send_email()

if __name__ == '__main__' :
	main()


