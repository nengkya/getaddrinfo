import requests

# Target website (no trailing slash)
#BASE_URL = "http://esdm.go.id"
BASE_URL = "http://gojek.com"

# Simple wordlist
WORDLIST = [
    "admin",
    "login",
    "uploads",
    "images",
    "backup",
    "config"
]

# Optional: timeout to avoid hanging
TIMEOUT = 3

def dir_buster(base_url, wordlist):
    for word in wordlist:
        url = f"{base_url}/{word}"
        try:
            response = requests.get(url, timeout=TIMEOUT)

            if response.status_code != 404:
                print(f"[+] Found: {url} (status={response.status_code})")

        except requests.RequestException as e:
            print(f"[!] Error checking {url}: {e}")

if __name__ == "__main__":
    dir_buster(BASE_URL, WORDLIST)
