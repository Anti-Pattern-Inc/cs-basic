<?php

$socket = stream_socket_server("tcp://0:3000");

while (true) {

    $stream = stream_socket_accept($socket, -1);
    $filename = "";

    while ($line = fgets($stream)) {
        echo $line;

        $col = explode(" ", $line);
        if ($col[0] == "GET") {
            $filename = $col[1];
        }
        if ($line == "\r\n") {
            break;
        }
    }

    if ($filename == "/") {
        $filename = "/index.html";
    }
    $filename = "content" . $filename;

    // ファイルが無かった場合は404
    if (!file_exists($filename)) {
        fputs($stream, "HTTP/1.1 404 NOT FOUND\r\n");
        fputs($stream, "\r\n");
        fclose($stream);
        continue;
    }

    $body = file_get_contents($filename, false);
    $type = mime_content_type($filename);

    // すごい無理矢理 MIME Type 変換
    if ($type == "text/x-asm") {
        $type = "text/css";
    }

    fputs($stream, "HTTP/1.1 200 OK\r\n");
    fputs($stream, "Content-Type: " . $type . "\r\n");
    fputs($stream, "\r\n");

    fputs($stream, $body);

    fclose($stream);
}
