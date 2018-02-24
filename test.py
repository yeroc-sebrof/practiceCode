# Debugging my regex code

import sys
import re

ipRange = "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)"

check = re.search("\A" + ipRange + "\." + ipRange + "\."
		 + ipRange + "\." + ipRange + "\Z", sys.argv[1])

print (check)

print (None == check)
