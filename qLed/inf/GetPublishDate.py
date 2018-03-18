# -*- coding: UTF-8 -*-

import os, sys
os.environ['NLS_LANG'] = 'SIMPLIFIED CHINESE_CHINA.UTF8'
import requests, json

urlBase = "http://192.168.17.187/aqms/"
publishInf = urlBase + "main/publish"

def APIRequest(api_url, data, headers=None, verify=False):
    if not headers:
        headers = {"content-type": "application/json"}
    data = json.dumps(data)
    try:
        response = requests.post(api_url, data=data, headers=headers, verify=verify)
    except httplib.IncompleteRead, e:
        response = e.partial

    response = response.json()

    if response["rescode"] == '200':
        result = response["detail"]
    else:
        errorInfo = response["errInfo"]
        raise Exception("API request error: {0}".format(errorInfo))
    return result

def checkConfig():
    with open("./config.json","r") as load_f:
        load_dict = json.load(load_f)
        print("load OK.")

        if "urlBase" in load_dict:
            print load_dict["urlBase"]
            urlBase = load_dict["urlBase"]
            publishInf = urlBase + "main/publish"

        print load_dict["winList"]
        return load_dict["winList"]

def Main():
    winList = checkConfig()
    for item in winList:
        stationID = item["stationID"]
        winID = item["winID"]
        reqDate = {"action": "getCallerList", "stationID": stationID, "callerID": winID}
        ret = APIRequest(publishInf,reqDate)
        print ret
        winList = list(ret["list"])
        item = winList[0]
        queueName = item["queueInfo"]["queueName"]

        for item in winList:
            #if item["listInfo"]["seeing"]["show"] == 1:
            name = item["listInfo"]["seeing"]["name"]
            pos = item["queueInfo"]["pos"]
            do = item["queueInfo"]["outputText"]
            str = "请%s到%s%s" %(name,pos,do)
            print str


# startup
if __name__ == "__main__":
    Main()


