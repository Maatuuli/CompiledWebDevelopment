import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.logging.LogEntries;
import org.openqa.selenium.logging.LogEntry;

import java.util.Date;
import java.io.IOException;
import java.nio.file.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.text.NumberFormat;
import java.text.ParseException;
import java.lang.Number;

public class Helper
{
    public static WebDriver
    getChromeWebDriver()
    {
        ChromeOptions options = new ChromeOptions();
        options.addArguments("--incognito");
        options.addArguments("--headless=new");

        System.setProperty("webdriver.chrome.driver", "./chromedriver");

        WebDriver driver = new ChromeDriver(options);

        /* Setup default size for browser window. */
        int browser_width = 1200;
        int browser_height = 600;
        driver.manage().window().setSize(new Dimension(browser_width, browser_height));

        return driver;
    }


    public static void
    sleepInMilliSeconds(int milliSeconds)
    {
        try
        {
            Thread.sleep(milliSeconds);
        }
        catch (InterruptedException interrupted_exception)
        {
            System.out.println(" ");
            System.out.println("ERROR: Thread.sleep(...) throws an exception: " + interrupted_exception.getMessage());
            System.out.println(" ");
        }
    }


    public static void
    appendTextToLogFile(String text)
    {
        try
        {
            // DateFormat dateFormat = new SimpleDateFormat("HH:mm:ss");

            // String line = dateFormat.format(new Date());
            // line += " ";
            String line = text;
            line += System.getProperty("line.separator");

            Files.write(Paths.get("automated_test_cases.log"), line.getBytes(), StandardOpenOption.APPEND);
        }
        catch (IOException ioException)
        {
            System.out.println("[ERROR] Exception IO Logging: " + ioException.getMessage());
        }
    }


    public static WebElement
    getWebElementByXpath(WebDriver driver, String xpathText)
    {
        WebElement element = null;

        try
        {
            element = driver.findElement(By.xpath(xpathText));
        }
        catch (Exception exception)
        {
            return null;
        }

        return element;
    }


    public static String
    getBaseUrlForAutomatedTests()
    {
        return "https://maatuu.li/CompiledWebDevelopment/";
    }


    public static int
    getHttpStatusCodeByBrowserLogs(LogEntries entries, String expectedUrl, String actualUrl)
    {
        int statusCode = 200;

        for (LogEntry entry : entries) {
            if (!entry.getLevel().toString().contains("SEVERE"))
            {
                continue;
            }

            if (
                (!entry.getMessage().contains(expectedUrl))
                && (!entry.getMessage().contains(actualUrl))
            )
            {
                continue;
            }

            String textForSearch = "responded with a status of ";
            int position = entry.getMessage().indexOf(textForSearch);

            int startPosition = position + textForSearch.length();
            String statusCodeText = entry.getMessage().substring(startPosition, startPosition + 3);

            try {
                statusCode = Integer.parseInt(statusCodeText);
            } catch (NumberFormatException nfe) {
                // Logging.
            }

            if (statusCode != 200)
            {
                System.out.println("[INFO] HTTP status code " + statusCode);
                System.out.println("[INFO] from actual URL: \"" + actualUrl + "\"");
                System.out.println("[INFO] with expected URL: \"" + expectedUrl + "\"");
            }
        }

        return statusCode;
    }
}
