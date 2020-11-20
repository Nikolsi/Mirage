#!/bin/sh -e

# Git command to update all the submodules of the entire repo to keep the dependencies up-to-date
git submodule update --remote --merge