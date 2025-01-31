const getData = (callback) => { 
    const req = new XMLHttpRequest(); // 0 -> requestReady
    // let i = 0;
    req.addEventListener('readystatechange', () => {
        // i += 1;
        if (req.readyState == 3){
            console.log("LOADING...");
        }
        if (req.readyState === 4 && req.status === 200){
            const data = JSON.parse(req.responseText);
            callback(req.status, data);
        }else if (req.readyState === 4){
            callback(req.status, req.responseText);
        }
    });
    req.open('GET', "/todos.json"); // 1 -> request Ready
    req.send(); // 2 -> RequestReady

    // 3 -> request Ready (LOADING) 
    // 4 -> request Ready (DONE)
}
console.log("FIRST");
// this is a async code !
getData(
    (status, data) => {
        if (status == 200){
            console.log("OK!");
            console.log(data);
        }else if (status == 404){
            console.log("NOT FOUND!")
        }else{
            console.log("FAILED!");
        }
    }
);

console.log("LAST");
