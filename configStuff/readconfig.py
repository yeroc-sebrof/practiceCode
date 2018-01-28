"""
Config contains two test variables and a port to scan with nmap
This script should be able to read that from the config file called config.ini
"""

import configparser

config = configparser.ConfigParser()
config.read('config.ini')

for key in config['DEFAULT']:
    print(key)

# pushes lowercase even though port has caps (This just makes things easier I suppose)
if 'port' in key:
    print('\nPort is there', end=":")

# but this works fine regardless
if 'port' in key:
    print(config['DEFAULT']['Port'])
