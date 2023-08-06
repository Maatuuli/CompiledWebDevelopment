import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.logging.LogEntries;
import org.openqa.selenium.logging.LogEntry;
import org.openqa.selenium.PageLoadStrategy;
import org.openqa.selenium.JavascriptExecutor;

import java.io.IOException;
import java.nio.file.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.text.NumberFormat;
import java.text.ParseException;
import java.lang.Number;
import java.util.Date;
import java.time.Duration;

public class Helper
{
    public static WebDriver
    getChromeWebDriver()
    {
        System.setProperty("webdriver.chrome.driver", "./chromedriver");
        System.setProperty("webdriver.chrome.logfile", "./chromedriver.log");
        System.setProperty("webdriver.chrome.verboseLogging", "true");

        ChromeOptions options = new ChromeOptions();
        options.addArguments("--incognito");
        options.addArguments("--disable-infobars");
        options.addArguments("--disable-notifications");

        options.setAcceptInsecureCerts(true);
        options.setPageLoadStrategy(PageLoadStrategy.NONE); // PageLoadStrategy.NONE or PageLoadStrategy.EAGER
        options.setHeadless(false);
        // options.setUnhandledPromptBehaviour​(UnexpectedAlertBehaviour.ACCEPT);

        WebDriver driver = new ChromeDriver(options);

        /* Setup default size for browser window. */
        int browser_width = 1200;
        int browser_height = 600;
        driver.manage().window().setSize(new Dimension(browser_width, browser_height));
        
        driver.manage().timeouts().pageLoadTimeout(Duration.ofSeconds(30));
        driver.manage().timeouts().setScriptTimeout(Duration.ofSeconds(30));

        return driver;
    }

    public static void
    waitUntilReadyStateIsInteractive(WebDriver driver)
    {
        WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(30));
        JavascriptExecutor executor = ((JavascriptExecutor) driver);
        wait.until(x -> {
            String readyState = (String) executor.executeScript("return document.readyState");
            return !readyState.equals("loading");
        });
    }

    public static void
    waitUntilReadyStateIsComplete(WebDriver driver)
    {
        WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(30));
        JavascriptExecutor executor = ((JavascriptExecutor) driver);
        wait.until(x -> {
            String readyState = (String) executor.executeScript("return document.readyState");
            return readyState.equals("complete");
        });
    }

    public static void
    sleepInMilliSeconds(int milliSeconds)
    {
        try
        {
            Thread.sleep(milliSeconds);
        }
        catch (InterruptedException exception)
        {
            System.out.println(" ");
            System.out.println("ERROR: Thread.sleep(...) throws an exception: " + exception.getMessage());
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


    public static boolean
    existWebElementByXpath(WebDriver driver, String xpathText)
    {
        try
        {
            driver.findElement(By.xpath(xpathText));
            return true;
        }
        catch (Exception exception)
        {
            return false;
        }
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
                Helper.appendTextToLogFile("[INFO] HTTP status code " + statusCode);
                Helper.appendTextToLogFile("[INFO] from actual URL: \"" + actualUrl + "\"");
                Helper.appendTextToLogFile("[INFO] with expected URL: \"" + expectedUrl + "\"");
            }
        }

        return statusCode;
    }
}
