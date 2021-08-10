#!/bin/bash
parallel mra {} -z ../zip -A ::: *.mra
