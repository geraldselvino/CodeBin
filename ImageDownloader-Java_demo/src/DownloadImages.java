import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.io.IOException;
import java.net.URL;
import java.net.HttpURLConnection;


public class DownloadImages {
    private String webSiteURL;
    private String folderPath;
    private javax.swing.JFrame mainFrame = null;
 
    public DownloadImages(String pURL, String pDownloadPath, javax.swing.JFrame pMainFrame) {
        webSiteURL = pURL;
        folderPath = pDownloadPath;
        mainFrame = pMainFrame;
    } 
    
    public void BeginDownload() {
        try {
            Document doc = Jsoup.connect(webSiteURL).get();
            Elements img = doc.getElementsByTag("img");

            for (Element el : img) {
                String src = el.absUrl("src");
                getImages(src);
            }
        } 
        catch (IOException ex) {
            Logger.getLogger(DownloadImages.class.getName()).log(Level.SEVERE, null, ex);
        }
        finally {
            ((DownloadImageFromWebpage)mainFrame).getProgressBar().setValue(0);
            ((DownloadImageFromWebpage)mainFrame).getDownloadLabel().setText("");
            ((DownloadImageFromWebpage)mainFrame).repaint();
        }
    }

    private void getImages(String src) throws IOException {

        int indexname = src.lastIndexOf("/");
        if (indexname == src.length()) {
            src = src.substring(1, indexname);
        }

        indexname = src.lastIndexOf("/");
        String name = src.substring(indexname, src.length());

        ((DownloadImageFromWebpage)mainFrame).getDownloadLabel().setText(name);
     
        URL url = new URL(src);
        HttpURLConnection httpConn = null;
        InputStream in = null;
        OutputStream out = null;
        
        try
        {
            httpConn = (HttpURLConnection) url.openConnection();
            int contentLength = httpConn.getContentLength();
            int currentProgress = 0;
            in = httpConn.getInputStream();

            if(((DownloadImageFromWebpage)mainFrame).getProgressBar() != null) {
                ((DownloadImageFromWebpage)mainFrame).getProgressBar().setMaximum(contentLength); 
                ((DownloadImageFromWebpage)mainFrame).getProgressBar().setValue(currentProgress);
                ((DownloadImageFromWebpage)mainFrame).getProgressBar().setStringPainted(true);   
            }

            out = new BufferedOutputStream(new FileOutputStream(folderPath + name));
            int bytesRead;

            while ((bytesRead = in.read()) != -1) {
                out.write(bytesRead);
                currentProgress += bytesRead; 
                if(((DownloadImageFromWebpage)mainFrame).getProgressBar() != null) {
                    ((DownloadImageFromWebpage)mainFrame).getProgressBar().setValue(currentProgress);
                    ((DownloadImageFromWebpage)mainFrame).getProgressBar().repaint();
                }
            }
        }
        finally
        {
            if(out != null){
                out.close();
            }
            if(in != null){
                in.close();
            }
            if(httpConn != null){
                httpConn.disconnect();
            }
        }
    }
}
