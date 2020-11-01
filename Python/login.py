from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import sys
import os
import time
import json

with open('me.json') as f:
  credentials = json.load(f)

driver=webdriver.Chrome("chromedriver")
driver.maximize_window()
driver.get("https://www.instagram.com/")
time.sleep(2)
driver.find_element_by_xpath("//input[@name=\"username\"]").send_keys(credentials["Username"])
driver.find_element_by_xpath("//input[@name=\"password\"]").send_keys(credentials["Password"])
driver.find_element_by_xpath("//button[@type=\"submit\"]").click()

securitycode = str(input())

driver.find_element_by_xpath("//input[@name=\"verificationCode\"]").send_keys(securitycode)
time.sleep(2)
driver.find_element_by_xpath("//button[text()=\"Confirm\"]").click()
time.sleep(10)
driver.find_element_by_xpath("//button[text()=\"Not Now\"]").click()
login_button.click()

time.sleep(5)
driver.quit()
