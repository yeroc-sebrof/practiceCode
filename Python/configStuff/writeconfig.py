"""
Config contains two test variables and a port to scan with nmap
This script should be able to read that from the config file called config.ini
"""

import configparser

config = configparser.ConfigParser()
config['DEFAULT'] = {'test1': 'yes',
                     'test2': '7',
                     'port': '55000'}
