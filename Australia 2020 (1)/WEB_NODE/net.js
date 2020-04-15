const http = require(id:'http');
const pid = process.pid;


http
   
   .createServer (requestListener: (req, res ) =>{
        for (let i = 0; i<1e7; i++) {}
        res.end(chunk:'Hello Server from Node,js');	

   })
   .listen(port:8800, listeningListener () => 

   {

   	console.log('Server started. Pid: ${pid}');
     


   });

   process.on(event:'SIGINT',listener:() => {
    console.log('Signal is SIGINT');
    server.close(callback:() => {
    	process.exit(code:0);
    })
   });
   process.on(event:'SIGTERM', listener:() => {
     console.log('Signal is SIGTERM');
     server.close(callback: () => {
     	process.exit(code:0);
     })
   });