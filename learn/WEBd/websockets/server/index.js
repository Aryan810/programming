import express from "express"
import {WebSocketServer} from "ws"

// making app
const app = express();
const port = 4000
const server = app.listen(port, () => {
    console.log("Server is listening at port %d ....", port);
});

const wss = new WebSocketServer({server});

wss.on("connection", (ws) => {
    console.log("connection estd. with ", ws.url);
    ws.on("message", (data)=>{
        console.log("Data from client: %s", data);
        for (let i=0;i<Number(String(data));i++){ws.send("Thanks for this message " + String(i));}
    });

});

wss.on("close", () => {
    console.log("connection closed !");
})