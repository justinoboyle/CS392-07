#!/bin/bash

echo "c1" | ./example 127.0.0.1 1025 &
echo "c2" | ./example 127.0.0.1 1025 &
echo "c3" | ./example 127.0.0.1 1025 &
