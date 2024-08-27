FROM texlive/texlive:latest

RUN apt-get update
RUN apt-get install -y wget fontconfig unzip git 

# ARG CACHEBUST=1
# RUN git clone https://github.com/Yuankai619/Mashu-Codebook.git

RUN mkdir -p /usr/share/fonts/truetype/consolas && \
    wget https://github.com/kakkoyun/linux.files/raw/master/fonts/Consolas.ttf -O /usr/share/fonts/truetype/consolas/Consolas.ttf && \
    chmod 644 /usr/share/fonts/truetype/consolas/Consolas.ttf && \
    fc-cache -fv

RUN wget https://noto-website-2.storage.googleapis.com/pkgs/NotoSansCJKtc-hinted.zip -O /usr/share/fonts/NotoSansCJKtc-hinted.zip && \
    unzip /usr/share/fonts/NotoSansCJKtc-hinted.zip -d /usr/share/fonts/NotoSansCJKtc/ && \
    chmod 644 /usr/share/fonts/NotoSansCJKtc/*.otf && \
    fc-cache -fv

RUN rm /usr/share/fonts/NotoSansCJKtc-hinted.zip
WORKDIR /codebook/Mashu-Codebook
COPY .fonts/ttf/ /usr/share/fonts/truetype/custom/

COPY ./ ./
ENTRYPOINT ["sh", "-c", "ls && tail -f /dev/null"]
