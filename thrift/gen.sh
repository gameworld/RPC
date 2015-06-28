#!/bin/sh
thrift --gen java timeService.thrift
thrift --gen cpp timeService.thrift
