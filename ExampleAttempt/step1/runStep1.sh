export siteName="www.example.com"
openssl s_client -connect ${siteName}:443 -showcerts > ${siteName}_out.txt
