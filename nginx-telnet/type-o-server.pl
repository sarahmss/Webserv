# (0) path to perl interpreter
#!/usr/bin/perl

# (0.1) Loading modules
use Socket;                # Network communication
use Carp;                  # Error management
use FileHandle;            # File management

# (1) use port 8080 by default, unless overridden on command line
$port = (@ARGV ? $ARGV[0] : 8080);

# (2) create local TCP socket and set it to listen for connections
$proto = getprotobyname('tcp');                              
socket(S, PF_INET, SOCK_STREAM, $proto) || die;              
setsockopt(S, SOL_SOCKET, SO_REUSEADDR, pack("l", 1)) || die;
bind(S, sockaddr_in($port, INADDR_ANY)) || die;
listen(S, SOMAXCONN) || die;

# (3) print a startup message
printf("<<Type-O-Serve Accepting on port %d>>>\n\n", $port);

while(1)
{
	# (4) Wait for a connection C
	$cport_caddr = accept(C, S);
	($cport, $caddr) = sockaddr_in($cport_caddr);
	C->autoflush(1);

	# (5) print who the connection is from
	$cnmae = gethostbyaddr($caddr, AF_INET);
	printf("<<Request From %d>>>\n\n", $cname);

# (6) read the request msg until the blank line, and print the screen
while($line = <C>)
{
	print $line;
	if($line =~ /^\r/) { last; }
}

# (7) prompt for response message and input response lines,
# sending response lines to cliente, until solitary "."
printf("<<<Type Response follweb by '.'>>>\n");
while($line = <STDIN>)
{
	$line =~ s/\r//;
	$line =~ s/\n//;
	if ($line =~ /^\./) {last;}
	print C $line . "\r\n";
}
close(C);
}
