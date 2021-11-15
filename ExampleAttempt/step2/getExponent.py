debugFlg = False
def debugLog(message):
    if(debugFlg):
        print("DEBUG: " + str(message))

def getExponent(lines):
    debugLog(lines)

    exponent = "nothing"

    for line in lines:
        stringToFind = "Exponent: "
        startIndex = line.find(stringToFind)
        
        if(startIndex == -1):
            continue
        else:
            endOfFoundString = startIndex + len(stringToFind)
            debugLog(endOfFoundString)


            exponent = collectCharsBeforeWhiteSpace(line, endOfFoundString)
            debugLog(exponent)

            break
    return exponent

def collectCharsBeforeWhiteSpace(line, startIndex):
    collectedChars = ""
    currIndex = startIndex
    maxIndexCnt = len(line)
    while(line[currIndex] != ' ' and (currIndex < maxIndexCnt)):
        collectedChars+=line[currIndex]
        currIndex+=1

    return collectedChars
    
if(__name__ =='__main__'):
    fileName = 'runStep2_out_2.txt'
    lines=[]

    with open(fileName , 'r') as f:
        lines = f.readlines()
    
    exp = getExponent(lines)
    
    print(exp)	

        
    
