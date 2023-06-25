all:
	@echo -n "building nginx img: "
	@docker build -t nginx .
	@echo "Ok!! "
	@echo "Running nginx img: "
	@docker run -d -p 80:80 nginx
	@echo "stabilisshing telnet connection: "
	@telnet localhost 80

get:
	GET /usr/share/nginx/html/index.html HTTP/1.1
	Host: localhost

put:
	PUT /file.txt HTTP/1.1
	Host: localhost
	Content-Type: text/plain
	Content-Length: 13

	Hello, World!

delete:
	DELETE /file.txt HTTP/1.1
	Host: localhost

post:
	POST /submit-form HTTP/1.1
	Host: localhost
	Content-Type: application/x-www-form-urlencoded
	Content-Length: 21

	name=John&age=30&city=NY

head:
	HEAD /index.html HTTP/1.1
	Host: localhost