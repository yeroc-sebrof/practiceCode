# Debugging my regex code

import sys
import re

ipRange = "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)"  # This checks a number is within 0-255
anIPv4 = ipRange + "\." + ipRange + "\." + ipRange + "\." + ipRange  # This regex will check its a IP
anIPv4Range = anIPv4 + "\-" + anIPv4  #This checks its a range such as 1.1.1.1-2.2.2.2

theOtherRange = anIPv4 + "\/[0-2][0-9]|" + anIPv4 + "\/3[0-2]"  # This checks its the other IP range such as 192.168.0.0/24
								# The checks with this one are more lax. Still error prone


check = re.search("\A" + anIPv4 + "\Z|\A" + anIPv4Range + "\Z|\A" + theOtherRange + "\Z", sys.argv[1])

print (check)

print (check is None)
