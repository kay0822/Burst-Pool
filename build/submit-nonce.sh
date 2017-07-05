#!/bin/sh

curl --url "http://127.0.0.1:9876/burst" --data-ascii "requestType=submitNonce&accountId=15188591833767009677&nonce=$1"
echo ''
curl --url "http://127.0.0.1:9876/burst" --data-ascii "requestType=submitNonce&accountId=5085825464960632136&nonce=$1"
echo ''
