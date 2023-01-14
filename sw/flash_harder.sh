#!/bin/bash
until pio run -e mimu_phantom -t upload
do
    echo ...
    sleep 1
done
