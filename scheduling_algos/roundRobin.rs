struct Process{
    name: String,
    pid: i32,
    arrivalTime: i32,
    waitTime: i32,
    cpuBurst: i32,
    taTime: i32,
    remExecTime: i32
}

fn main(){
    let procQueue: Vec = vec![Process{name:"Proc 1", pid: 1, arrivalTime: 1, cpuBurst: 10}]
}


