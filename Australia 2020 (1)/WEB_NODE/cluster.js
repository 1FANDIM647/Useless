const cluster = require (id: 'cluster');
const os =require (id 'os');
const pid = process.pid;

if (cluster.isMaster){
  const cpusCount = os.cpus().length;
  console.log('CPUs: ${cpusCount}');
  console.log('Master started. Pid: ${pid}');
  console.fork();
}
if (cluster.isWorker)
{
  require(id: './worker.js'); 
}