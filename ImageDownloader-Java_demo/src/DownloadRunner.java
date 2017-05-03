public class DownloadRunner implements Runnable {
    private Thread t;
    private String mUrl;
    private String mDownloadPath;
    private javax.swing.JFrame mMainFrame = null;
    
    DownloadRunner(String pURL, String pDownloadPath, javax.swing.JFrame pMainFrame) {
       t = new Thread(this, "DownloadThread");
       mUrl = pURL;
       mDownloadPath = pDownloadPath;
       mMainFrame = pMainFrame;
    }
    
    public void startDownload() {
        t.start();
    }
    
    @Override
    public void run() {
        DownloadImages gDownloadImage = new DownloadImages(mUrl, mDownloadPath, mMainFrame);
        gDownloadImage.BeginDownload();
    }
}
