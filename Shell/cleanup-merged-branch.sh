# Becuase of Bitbucket allow "Delete source branch after merging" is not enabled by default. https://jira.atlassian.com/browse/BSERV-9254
# Here's an alias that's useful for removing merged branches. 
# It only cares about local ones but you could modify it to hit your servers if you really want. Use at your own risk, of course.

cleanup = "!git branch --merged | grep -v '\\*\\|master\\|develop\\|release' | grep -v master | grep -v release | grep -v develop | xargs -n 1 git branch -d"